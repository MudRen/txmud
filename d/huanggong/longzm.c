// Room: /d/huanggong/longzm.c

inherit ROOM;

void create()
{
        set("short", "¡����");
        set("long", @LONG
������ȥ���ĵ�Ͷ����ıؾ�֮·��һ����ΰ�Ĵ��ų�����
����ǰ�������������ܣ����Ķ��ǣ�ש�񶷹���������ǧ����һ
�ж���ʾ�߻ʼҵ����������ϣ������ƿɼ�һ�ߣ���ΰ׳��Ī��
�ڴ�.
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"yangxd",
  "southeast" : __DIR__"baohd",
]));
        set("no_clean_up", 0);

	set("outdoors", "huanggong");
        setup();
        replace_program(ROOM);
}

