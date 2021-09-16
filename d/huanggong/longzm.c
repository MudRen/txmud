// Room: /d/huanggong/longzm.c

inherit ROOM;

void create()
{
        set("short", "隆宗门");
        set("long", @LONG
这里是去养心殿和东宫的必经之路，一座雄伟的大门呈现在
你眼前。但见高柱飞檐，勾心斗角，砖雕斗拱，气象万千，这一
切都显示者皇家的气派与尊严，其气势可见一斑，宏伟壮观莫过
于此.
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"yangxd",
  "southeast" : __DIR__"baohd",
]));
        set("no_clean_up", 0);

	set("outdoors", "huanggong");
        setup();
        replace_program(ROOM);
}

