// /d/yuehou/house2.c

inherit ROOM;

void create()
{
        set("short", "�ӻ���");
        set("long", @LONG
��������������ӻ��꣬��������˴�඼������������
������ϰ����ڲ�ͣ��æµ�ţ��ƺ��ڵȴ���ʲô����������
��С����м���
LONG
        );

       set("exits", ([
                "north"             : __DIR__"troad4",
]) );

       set("light_up",1);

       setup();
       replace_program(ROOM);
}
