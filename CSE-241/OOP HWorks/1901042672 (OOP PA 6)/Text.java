public class Text extends Entity implements NonPlayable, NonVisual{
    int font;
    public Text(String n, int newFont){
        super(n);
        font = newFont;     // text is entity and has a font
    }

    public void setFont(int newFont){font = newFont;}

    public void info(){     //print text info.
        System.out.println("Text:");
        System.out.println("name: "+ name + ", font: " + font);
        System.out.println();
    }
}
