public class Procesor
{
    private String _name;
    private String _type;
    private double _frecventa;
    private double _price;

    public Procesor(String name, String type, double frecventa, double price)
    {
        this._name = name;
        this._type = type;
        this._frecventa = frecventa;
        this._price = price;
    }

    public String getName()
    {
        return _name;
    }

    public String getType()
    {
        return _type;
    }

    public double getfrecventa()
    {
        return _frecventa;
    }

    public double getPrice()
    {
        return _price;
    }

    public void setName(String name)
    {
        this._name = name;
    }

    public void setType(String type)
    {
        this._type = type;
    }

    public void setfrecventa(double frecventa)
    {
        this._frecventa = frecventa;
    }

    public void setPrice(double price)
    {
        this._price = price;
    }

    public String toString()
    {
        return _name +" "+ _type +" "+  _frecventa +" "+ _price;
    }
}