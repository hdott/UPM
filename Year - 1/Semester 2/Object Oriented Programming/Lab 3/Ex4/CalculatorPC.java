public class CalculatorPC
{
    private HardDisk _hard;
    private MemorieRAM _ram;
    private Procesor _processor;
    private PlacaBaza _placaBaza;

    public CalculatorPC(HardDisk hard, MemorieRAM ram, Procesor procesor,
                        PlacaBaza placaBaza)
    {
        this._hard = hard;
        this._ram = ram;
        this._procesor = procesor;
        this._placaBaza = placaBaza;
    }

    public CalculatorPC(String name, String type, double size, double speed, 
                        double price, String object)
    {
        if(object=="hard disk")
            this._hard(name,type,size,speed,price);
        else
            this._ram(name,type,size,speed,price);
    }

    public CalculatorPC(String name, String type, double frecventa, double price)
    {
        this._processor(name,type,frecventa,price);
    }

    public CalculatorPC(String name, String type, String supportedProcessor,
                        String supportedRAM, double price)
    {
        this._placaBaza(name,type,supportedProcessor,supportedRAM,price);
    }

    public double finalPrice()
    {
        return _hard.getPrice() + _ram.getPrice() + _processor.getPrice() +
                _placaBaza.getPrice();
    }

    public boolean componentCompatibilty()
    {
        if(_ram.getType() == _placaBaza.getSupportedRAM() &&
            _processor.getType() == _placaBaza.getSupportedProcessor())
            return true;
        else    return false;
    }
}