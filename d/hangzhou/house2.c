// Room: /d/hangzhou/house2.c

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
���������ǿ�������������ض���Ȼ�������һ����ɫ��
ɫ�ľ�����ױ̨��ǰ��������ź�ľԲ�Ρ��Ҳ�ǽ���Ϲ���һ��
��Ů����ͼ���������м��бʼ����������С�֣��ڲ�����һ��
��ɫ��ᣴ��ҵĵͰ�ľ齣���������һ����Ϊ��ʵ�ļ�ͥ����
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"stoneroad2",
	"west" : __DIR__"house5",
]));

	set("objects",([
	__DIR__"npc/shaonian" : 1,
]));

	setup();
	replace_program(ROOM);
}
