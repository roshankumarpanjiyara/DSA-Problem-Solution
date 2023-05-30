class ParkingSystem {
    int b, m, s;
    public ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium;
        s = small;
    }
    
    public boolean addCar(int carType) {
        if(carType == 1){
            if(b < 1){
                return false;
            }
            b--;
        }else if(carType == 2){
            if(m < 1){
                return false;
            }
            m--;
        }else if(carType == 3){
            if(s < 1){
                return false;
            }
            s--;
        }
        return true;
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */
