//shanyao.c

inherit ITEM;

void create()
{
        set_name("山药", ({ "shan yao"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "株");
                set("long", 
"一株普通的山药,山药的甘平,用于补中益肺，固肾止泻。\n");
        }
}
