// Room: /d/huashan/lin1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ï�ܵ����ּ���¶��һ��С·�����ܳ��˶��͵�ɽ�ֿ�����
�κζ�����·�߲ݴ��������ż���Ұ����ֻ��ϧ��в������֡�
��ס�Ͼ�Ҫ��Т�ӷ��ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"yy_dong",
  "northwest" : __DIR__"xiaozi_feng",
  "southeast" : __DIR__"xiaolu2",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
