// Room: /d/huashan/shanquan.c

inherit ROOM;

void create()
{
	set("short", "ɽȪ");
	set("long", @LONG
�ֱߵ���ʯ�γ�һ���ݿڣ�ɽ�����µ�Ȫˮ������㼯��һ
̶��������ȥ��Ϫˮ����͸�ף���������ˮ��������������
(fill)һЩ�����򶫱�ȥ����Ҫ����ɽ�Ķ����ˡ��ϱ��ǻ�ɽ��
����Ʒ���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"quanshui",
  "eastup" : __DIR__"dongfeng",
  "southwest":__DIR__"jiufang",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
