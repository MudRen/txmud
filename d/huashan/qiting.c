// Room: /d/huashan/qiting.c

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����һ��Сͤ�ӣ��м���һ��ʯ���������ݺ���ʮ�ĵ�����
Ȼ��һ�����̡���紵�������鱶���泩��ÿ�����ʮ�壬ɽ��
���޵ĳ������ͻ��������һλ�����д����ա�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"lin2",
  "west" : __DIR__"xiaolu2",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
