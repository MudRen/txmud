// Room: /u/w/wangs/b/kai68.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������ֺ�ᶫ�����ѿ���Ƿֳ����롣·����������������
�ܶ������Ǻ�«�ġ���ζС�Ե�С�̷����ؽֽ���������������
�ϣ������и��ܵ��������ķ�����������·�ϱ���һ����Ժ����
�������������ǵ�����鱦�У����򶫲�Զ�������Ľ��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai70",
  "north" : __DIR__"kai69",
  "west" : __DIR__"kai65",
  "east" : __DIR__"kai71",
]));
        set("objects",([
        __DIR__"npc/beggar": 1,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
