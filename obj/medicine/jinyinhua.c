// jinyinhua.c

inherit ITEM;

void create()
{
        set_name("金银花", ({ "jin yin hua"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "株");
                set("long", 
"一株普通的金银花,金银花的性味甘寒,用于清热解毒。\n");
        }
}
