// Room: /u/w/wangs/b/kai180.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���������ǿ�������������ض���Ȼ�������һ����ɫ��
ɫ�ľ�����ױ̨��ǰ��������ź�ľԲ�Ρ��Ҳ�ǽ���Ϲ���һ��
��Ů����ͼ���������м��бʼ����������С�֣��ڲ�����һ��
��ɫ��ᣴ��ҵĵͰ�ľ齡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai156",
]));
        set("objects",([
        __DIR__"npc/xiaotou": 1,
]));

	setup();
	replace_program(ROOM);
}
