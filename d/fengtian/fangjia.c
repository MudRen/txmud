// Room: /d/fengtian/fangjia.c

inherit ROOM;

string go_enter(object me);

void create()
{
	set("short", "�����ּ�");
	set("long", @LONG
����һ����ͨ�Ĵ��߷������������ǳ��򵥣�ľ�����ϵ�
�����Ѿ����䣬�������ǳ��������������Ľ�ӡ������Ŀ��
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"kd9",
	"enter" : (: go_enter :),
]));

	setup();
}

string go_enter(object me)
{
	if(!me
	|| (me->query("class") != "rain")
	|| !me->query_temp("feiyu_upgrade_quest/ask_liehu"))
		return __DIR__"houyuan";

	return __DIR__"quest1";
}
