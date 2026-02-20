static const double R = 40;
static const double H = 1.00;
static double Q = 10;
static double P = 0;
static double K = 0;

void navigationKalmanFilter(double U, double U_hat) {

    K = P*H/(H*P*H+R); // update kalman gain
    U_hat = U_hat + K*(U-H*U_hat); // update estimated

    P = (1-K*H)*P+Q; // update error covariance
}