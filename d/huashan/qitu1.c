// Room: /d/huashan/qitu.c / by pian

inherit ROOM;

void create()
{
	set("short", "��;");
	set("long", @LONG
ï�ܵ����ּ���¶��һ��С·�����ܳ��˶��͵�ɽ�ֿ�����
�κζ���������С·�����ľ�������涼�����������������е�
��į���˸С�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"xiaolu4",
  "eastdown" : __DIR__"qitu2",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
