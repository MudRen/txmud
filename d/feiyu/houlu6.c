// Room: /wiz/louth/a/houlu6.c

inherit ROOM;

void create()
{
	set("short", "�ɻ�ͤ");
	set("long", @LONG
���������¥���Ϊ��֪�Ľ��䣬Ҳ��������������֮�ء�
���������������һ�˴��ࡰ��ܲ�ġ�����������Ҳ����������
����������ڶ��߻��졣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"houlu5",
]));
        set("objects", ([
                __DIR__"npc/huanerjj": 1,
        ]) );

	set("outdoors","feiyu");
	setup();
}

int valid_leave(object me,string dir)
{
	if( (dir == "southeast") && me->query_temp("mark/huaner_pu") )
		me->delete_temp("mark/huaner_pu");
	return ::valid_leave(me,dir);
}
