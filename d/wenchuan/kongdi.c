// kongdi.c С�յ� 

inherit ROOM;
void create()
{
        set("short", "С�յ�");
        set("long", @LONG
�����ǰ����һƬС�յأ��յ����м�ֻС�������ף��յ�
�ĺ�����һ��С�ݣ�������������ɫ�ĸ��֣��ſڵ�����в��
��ˮ�ס�
LONG
        );
       set("exits", ([
                "west"              : __DIR__"shulin2",
                "east"              : __DIR__"xiaowu",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
