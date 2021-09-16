// weapony.c  长安武器店

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "长安兵器坊");
        set("long", @LONG
这是是长安城最大的一家武器店，一进门可以看到两边陈列
着许多各式武器，你可以慢慢挑选你称手的武器。靠近门口的地
方有一块生铁铸就成的大招牌(sign)。南边是南大街。
LONG
        );
        set("exits", ([
                "south"           : __DIR__"nroad1",
]) );

	set("objects", ([
		__DIR__"npc/weaponboss" : 1,
]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌写著：欲先成其事 必先利其器
          本店专卖各式兵器，请随时光顾。\n";
}
