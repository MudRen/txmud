// Room: /d/huashan/xiaolu4.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
һֻ��Ϣ����·�ߵ����ϳ�����֨֨�ؽ��ţ��������㰵ʾ
��ʲô�������ҿ�����ȴʲôҲû���֡�С·�ı��ϳ���һЩ��
ɫ��ֲ��м���һ����ɫ�Ķ���������ϸһ����ԭ����һ����
�˵���β�ߡ�������С·ͨ����ϼ���ĺ��š�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"lianhua_feng",
  "southdown" : __DIR__"juling_zu",
  "east":__DIR__"qitu1",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
