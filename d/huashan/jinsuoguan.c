// Room: /d/huashan/jinsuoguan.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ǽ����أ���ͨ���Ϸ塢���塢������ʺ�������
�廷�������ն����ģ���������䣬���������ɾ���ɽ��һ����
��������СϪ����ɽ�¡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"wushangdong",
  "northwest" : __DIR__"xiaolu7",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
