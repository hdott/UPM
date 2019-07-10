public class Masina
{
    private String _type;
    private String _colour;
    private double _speed;

    public Masina()
    {
        this._type = "Sport";
        this._colour = "Blue";
        this._speed = 250.0;
    }

    public Masina(String type)
    {
        this._type = type;
        this._colour = "Red";
        this._speed = 190.5;
    }

    public Masina(String type, String colour)
    {
        this._type = type;
        this._colour = colour;
        this._speed = 205.7;
    }

    public Masina(String type, String colour, double speed)
    {
        this._type = type;
        this._colour = colour;
        this._speed = speed;
    }

    public String getType()
    {
        return _type;
    }

    public String getCoulour()
    {
        return _colour;
    }

    public double getSpeed()
    {
        return _speed;
    }

    public void setType(String type)
    {
        _type = type;
    }

    public void setColour(String colour)
    {
        _colour = colour;
    }

    public void setSpeed(double speed)
    {
        _speed = speed;
    }
}