//yaodian.c ��֥���ҩ�ꡣ
inherit ROOM;
void create()
{
        set("short", "Сҽ��");
        set("long", @LONG
��������֥���Сҽ�ݣ���Ϊ���ﲻ���˻Ṧ�򣬶��Ҵ�
�´��ԣ�������ЩС��С����Ҫ���õ�ҩ�������������ҽ��
�β�����ͬ��ͨ��ҽ�����𣬶�����˵����������ùƵģ���
���������һ�£��Ų���ʼ���ſ�Ų��
LONG
);
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
        "east":__DIR__"lz_sroad2",
]));

        set("objects",([
        __DIR__"npc/doctor":1,
        __DIR__"npc/xiaohuoji":1,
]));
        setup();
        replace_program(ROOM);
}
