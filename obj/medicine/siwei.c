// shiwei.c

inherit ITEM;

void create()
{
        set_name("石苇", ({ "shi wei"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "包");
                set("long", 
"一包普通的石苇,石苇的性味苦甘微寒,用于清湿热利小便。\n");
        }
}
