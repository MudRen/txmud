// Room: /d/huanggong/donggdm.c

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
�ƹ����ĵһ����ΰ�����Ĵ��ų���������ǰ����������
�š��������߾��Ƕ����ˣ���ǰ��ͥԺ����������÷������Լ��
�㣬����һ����ζ�����������÷�����е����������ڷ���....
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"dongg2",
  "south" : __DIR__"yangxd",
  "northwest" : __DIR__"dongg3",
]));
        set("no_clean_up", 0);
        set("outdoors", "huanggong");
	setup();
        replace_program(ROOM);
}