//ganchao.c

inherit ITEM;

void create()
{
        set_name("甘草", ({ "gan chao"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "株");
                set("long", 
"一株普通的甘草，甘草的性味甘平，用于补中益气，清热解毒。\n");
        }
}
