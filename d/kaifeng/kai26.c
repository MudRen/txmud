// Room: /u/w/wangs/b/kai26.c

inherit ROOM;

void create()
{
	set("short", "���ʵ�");
	set("long", @LONG
�������涼���ų����ĸ�¥�����ÿ������͵������������
�кӣ����������ʵĺ�ζ��������������á��������Ϻ����
з����װ��ˮ�����ÿ���Ӻ��������ģ����Ծ��Ե����ʣ�����
��ĳ�ʦ��˵����ǰ���ھ����ɵĳ����ĸɻ�ģ��������ճ���
��������˺ܶ��˵����Ʒ����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai25",
]));
        set("objects",([
        __DIR__"npc/haiboss": 1,
]));

	setup();
	replace_program(ROOM);
}
