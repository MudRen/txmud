// Room: /d/huashan/lin2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ï�ܵ����ּ���¶��һ��С·�����ܳ��˶��͵�ɽ�ֿ�����
�κζ�����·�߲ݴ��������ż���Ұ����ֻ��ϧ��в������֡�
·Խ��Խ�����ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"xiaolu2",
  "southdown" : __DIR__"qiting",
  "northeast" : __DIR__"xiaolu5",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
