// Room: /wiz/louth/k/kai143.c

inherit ROOM;

void create()
{
	set("short", "��ԡի");
	set("long", @LONG
�ڿ���Ķ�����ϱߣ��ſ������������ַǳ������õ�С��
��վ���ſ�Ц����ӭ����Ŀ��ˡ��ſ����Ϸ�����һ���޴�ĺ�
ľ���ң��������������֡�����ԡի�������������ٹ�����
��������ն�ϲ����������ƣ�͡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kai141",
  "south" : __DIR__"kai31",
]));
        set("objects",([
        __DIR__"npc/qianer": 1,
]));

	setup();
	replace_program(ROOM);
}
