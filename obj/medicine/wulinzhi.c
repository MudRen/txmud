// wulingzhi.c

inherit ITEM;

void create()
{
        set_name("五灵脂", ({ "wu ling zhi"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "株");
                set("long", 
"一株普通的五灵脂,五灵脂的性味苦温,用于行血去淤,通经
止痛。\n");
        }
}
