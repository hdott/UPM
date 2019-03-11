public class HardDisk
{
    private String _name;
    private String _type;
    private double _size;
    private double _speed;
    private double _price;

    public HardDisk(String name, String type, double size, double speed, double price)
    {
        this._name = name;
        this._type = type;
        this._size = size;
        this._speed = speed;
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

    public double getSize()
    {
        return _size;
    }

    public double getSpeed()
    {
        return _speed;
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

    public void setSize(double size)
    {
        this._size = size;
    }

    public void setSpeed(double speed)
    {
        this._speed = speed;
    }

    public void setPrice(double price)
    {
        this._price = price;
    }

    public String toString()
    {
        return _name +" "+ _type +" "+ _size +" "+ _speed +" "+ _price;
    }
}