public class ContBancar
{
    private double _sold = 0.0;

    public ContBancar(double sold)
    {
        _sold = sold;
    }

    public void depozitareSuma(double suma)
    {
        _sold += suma;
    }

    public boolean retrageSuma(double suma)
    {
        if(suma<_sold)
        {
            _sold -= suma;
            return true;
        }
        else
        {
            _sold -= suma;
            return false;
        }
    }

    public double getSold()
    {
        return _sold;
    }
}