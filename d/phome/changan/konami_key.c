// key.c
// 玩家的中文名如改名，此处应能自动更改。

inherit ITEM;
inherit F_AUTOLOAD;

int query_autoload () {return 1;}

void create()
{
        set_name("修道狼在长安城的家门钥匙", ({"home key","key"}));
        set("long",
                "这是一把铜钥匙，可能由于经常使用，被磨得闪闪发亮。\n");
        set("unit", "把");
        set("weight", 10);
        set("value", 0);
}

//void owner_is_killed() { destruct(this_object()); }
