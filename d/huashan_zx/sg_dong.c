// Room: /d/huashan/sg_dong.c

inherit ROOM;

void create()
{
        set("short", "˼����");
        set("long", @LONG
����һ����Ȼ��ɽ�������ﵹҲ��ˬ�����������һЩ��
�ݣ�����������������Ϣ����
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"siguoya",
]));

        setup();
        replace_program(ROOM);
}
