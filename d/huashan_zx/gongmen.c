// Room: huashan gongmen.c

inherit ROOM;

void create()
{
	set("short", "紫霞宫门");
	set("long",@LONG
这是一座气势磅礴的宫殿，宫门上一块金字横匾，上书三个
斗大的狂草--“紫霞宫”。这里就是华山派的大门了。门口分列
着两只威风懔懔的石狮子。大门东边是一片郁郁青青的草地，西
边是一片枫树林。石阶上摆着一只巨大的铜鼎，一丈多高的火苗
随风飞舞。
    据说铜鼎已经燃烧了上百年，也不知历经过多少世事变迁。
LONG
);

	set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"guangw1",
	"east": __DIR__"guange1",
	"north":__DIR__"doorgd",
]));

	set(SAFE_ENV,1);

	set("objects",([
	__DIR__"npc/dizi" : 2,
]));

	set("outdoors", "huashan_zx");
	setup();
}

int valid_leave(object ob,string dir)
{
	if(!ob || !stringp(dir))
		return 1;

	if( (dir == "north" || dir == "west")
        && ob->query("class") != "huashan"
	&& mapp(ob->query("family"))
        && !wizardp(ob) )
                return notify_fail("两名弟子伸手拦住你说道：本派重地，非华山弟子不得入内！！\n");

        else
                return ::valid_leave(ob,dir);
}
