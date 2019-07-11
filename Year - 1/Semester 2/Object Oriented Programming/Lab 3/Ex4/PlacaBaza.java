public class PlacaBaza
{
    private String _name;
    private String _type;
    private String _supportedProcessor;
    private String _supportedRAM;
    private double _price;

    public PlacaBaza(String name, String type, String supportedProcessor,
                        String supportedRAM, double price)
    {
        this._name = name;
        this._type = type;
        this._supportedProcessor = supportedProcessor;
        this._supportedRAM = supportedRAM;
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

    public String getSupportedProcessor()
    {
        return _supportedProcessor;
    }

    public String getSupportedRAM()
    {
        return _supportedRAM;
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

    public void setSupportedProcessor(String supportedProcessor)
    {
        this._supportedProcessor = supportedProcessor;
    }

    public void setSupportedRAM(String supportedRAM)
    {
        this._supportedRAM = supportedRAM;
    }

    public void setPrice(double price)
    {
        this._price = price;
    }

    public String toString()
    {
        return _name +" "+ _type +" "+ _supportedProcessor +" "+ _supportedRAM +
                " "+ _price;
    }
}