// key.c
// by aiai

inherit ITEM;

void create()
{
        set_name("钥匙", ({ "small key" }) );
        set_weight(500);

        set("unit","把");
        set("material", "iron");
        set("long", "这是一把生锈的钥匙。\n");
                set("for_xiuxiu", 1);
        setup();
}

