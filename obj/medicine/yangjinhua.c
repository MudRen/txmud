// mangxiao.c

inherit ITEM;

void create()
{
        set_name("洋金花", ({ "yang jin hua"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "支");
                set("long", 
"一支普通的山药,洋金花的性味辛温,用于平喘镇咳。\n");
        }
}
