// Room: /u/w/wangs/a/yu45.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�������������ϣ���������ֲ�˴�Ƭ���ɰأ�
�����дУ����Ǿ��ף�����������������Ҷ��ɳɳ���⣬��
����ʲô����������������������������һ�����ҡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"slroom1",
  "north" : __DIR__"yu44",
  "east" : __DIR__"slroom",
]));

	setup();
}

int valid_leave(object me,string dir)
{
	if( (dir == "west") || (dir == "east") )
	{
		if( (me->query("class") != "rain") && !wizardp(me) )
			return notify_fail("�����ﴫ��һ���������˵�ֻ�ܷ������ӽ��롣\n˵�Ű������˳�����\n");
	}
	return ::valid_leave(me,dir);
}
