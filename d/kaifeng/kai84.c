// Room: /u/w/wangs/b/kai84.c

inherit ROOM;

void create()
{
	set("short", "�˳�");
	set("long", @LONG
����ʳΪ�죬����һ�����з�ʢ���ֻҪ�������Ĳ��г���
��һĿ��Ȼ������Ĳ˳���Ȼ�����ַǳ�������ʱ�ʹ��ˡ�ɽ��
ˮ��������һ��ȱ��ÿ���峿���е�ʱ�������ĥ���������
�����С������ּۻ�������������˻�����ǲ����ڶ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai83",
]));

        set("objects",([
        __DIR__"npc/caiboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
