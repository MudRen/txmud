// Room: /d/changan/gongbu.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ǹ������ŵĴ��ã�����ȫ�������йؽ��췿�ݵ���
�鶼ͳ�鹤��������������һ���������͵����š����õ���ǰ
������һ���������顰�����������ĸ����֡�С�����Լ���ס
լҲ�ڴ˰�����������(buy)һ�������(shell)��д(fill)��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shigong",
  "west" : __DIR__"wroad6",
]));
	set(SAFE_ENV,1);
	set("no_sleep_room",1);

	set("objects",([
//        NPC_DIR"louashu" : 1,
]));
	setup();
	replace_program(ROOM);
}
