// Room: /d/hangzhou/linguard.c

inherit ROOM;

void create()
{
	set("short", "�Ҷ���");
	set("long", @LONG
�������ּҼҶ�ס�ĵط���һ���󷿼��������۵���ռ����
��䷿�ӵĴ�ͨ�������̴�ɨ�Ļ���ɾ�����һ�ߵ�ǽ�Ϲ��˲�
�ٵ���������
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"linneiyuan",
]));

	set("objects",([
	__DIR__"npc/jiading" : 1,
]));

	setup();
	replace_program(ROOM);
}
