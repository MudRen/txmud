// Room: /d/fengtian/jjf3.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ǽ�����ͺ���̸�������µĵط�������ǽ�Ϲ��˲���
�����ֻ����ɼ��������Ǵ���һ�������������һ�������ܣ���
�ϰ���һ�ѹ����ɫ�ı�����
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lang1",
  "west" : __DIR__"jjf2",
  "east" : __DIR__"jjf4",
  "north" : __DIR__"xf1",
]));

	setup();
	replace_program(ROOM);
}
