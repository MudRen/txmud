//cheqianchao.c

inherit ITEM;

void create()
{
        set_name("车前草", ({ "che qianchao"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "株");
                set("long", 
"一株普通的车前草，车前草的性味甘寒，用于利尿止泻，清热名目。\n");
        }
}
