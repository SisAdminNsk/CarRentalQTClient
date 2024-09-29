#ifndef CARSVIEWMODEL_H
#define CARSVIEWMODEL_H

#include <QWidget>

#include "API/DTO/loginresponse.h"
#include "API/Endpoints/Cars/Requests/getallcarsrequest.h"
#include <ViewModels/MainApplicationViewModels/NestedViewModels/CarItemCard/carcardviewmodel.h>

#include "Helpers/fromurlimageloader.h"

namespace Ui {
class CarsViewModel;
}

class CarsViewModel : public QWidget
{
    Q_OBJECT

public:
    explicit CarsViewModel(const LoginResponse& loginResponse, QWidget *parent = nullptr);
    ~CarsViewModel();
    void AddCar(CarCardViewModel *carCard);
private:
    FromURLImageLoader *urlImageLoader = nullptr;

    GetAllCarsRequest *getAllCarsRequest = nullptr;

    QList<CarCardViewModel*> cars;
    Ui::CarsViewModel *ui;

    void AddCarToGrid(CarCardViewModel *carCard);

    void InitializeCarCatalog();

    int cardWidth;
    int cardHeight;

    int currentRow = 0;
    int currentColumn = 0;
    int currentRowWidth = 0;

    int currentPage = 0;
    const int pageSize = 8;

private slots:
    void OnGettingAllCarsSuccess(const QList<CarDTO> &replyBody);
    void OnGettingAllCarsFailure(const QString& error);

    void OnAllImagesDownloaded(QList<CarCardViewModel*> carCards);

protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // CARSVIEWMODEL_H
