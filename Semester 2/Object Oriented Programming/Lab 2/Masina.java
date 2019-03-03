public class Masina
{
    private String _type;
    private String _colour;
    private double _speed;

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

    public String toString()
    {
        return _type +" "+ _colour +" "+ _speed;
    }
}