// Room: /d/huashan/xianzhangya.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һ��ɽ����һֻ���ֲ�����������ԡ�������������¡���
ȥ��̨��Ļ����㻹Ҫ����Ŭ���ˡ����²ݵ��ϳ��ż���Ұɽ��
�������������ǲ����Ʒ�֡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"wushangdong",
  "southdown" : __DIR__"xiaolu6",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
