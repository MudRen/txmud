// shiwei.c

inherit ITEM;

void create()
{
        set_name("百合", ({ "bai he"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "株");
                set("long", 
"一株普通的百合,百合的性味苦甘微寒,用于养阴清热。\n");
        }
}
