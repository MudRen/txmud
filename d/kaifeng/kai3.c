// Room: /u/w/wangs/b/kai3.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����·ͨ�򿪷���ڵ�һЩ���о��㣬���·����ȫ������
�������Ĵ���������·ԭ�Ȳ��к���·�ģ�ֻ����Ϊ����ʮ��ǰ��
��ʱ���ǽ���������С��Ĵ���ս������������һ�С��׺���ա�
һ��ȡ��Ϊ�����ֵĲɻ��޵������ĵ��׼�������Ϊ�˼����⾪
�춯�ص�һ�����㽫����·��������·�ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai4",
  "south" : __DIR__"kai2",
  "east" : __DIR__"kai5",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
