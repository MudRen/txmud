// Room: /u/w/wangs/b/kai95.c

inherit ROOM;

void create()
{
	set("short", "���Ľ�");
	set("long", @LONG
���Ľ��ǿ��⸮����ĵ��򣬽ֵ�һ�����������Ĺ㳡��
��һ�������������ӿ�볱�����ǵ�����䣬��������������
������磬����С�ԡ�̯����������ڴˣ�ʵΪ����һ���쾰��
���Ե������ְ��������Ľֽ��������Χ������
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai97",
  "north" : __DIR__"kai74",
  "west" : __DIR__"kai73",
  "east" : __DIR__"kai96",
]));
        set("objects",([
        __DIR__"npc/beggar": 1,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
