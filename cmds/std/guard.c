// guard.c
// Modified by Find.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string dir;
        object ob, *guards;
        mixed old_target;

        if( me->is_busy() )
                return notify_fail("������û�а취����ȥ�������£�\n");

        old_target = me->query_temp("guarding");

        if( !arg || arg=="" ) {
                if( !old_target )
                        return notify_fail("ָ���ʽ��guard <����>|<��Ʒ>|<����>\n");
                if( objectp(old_target) )
                        if( living(old_target) )
                                write("�������ػ���" + old_target->name() + "��\n");
                        else
                                write("��������" + old_target->name() + "һ�ԣ���ֹ�������ߡ�\n");
                else
                        write("������ס " + old_target + " �ķ��򣬲�׼�κ����뿪��\n");
                return 1;
        }

        ob = present(arg, environment(me));

        if( ob ) {
                if( ob==me ) return notify_fail("�����Լ�������˵��Ҳ�������԰ɡ�\n");

// added by find.
                if( ob->is_character() )
                {
                        if(arrayp(guards = ob->query_temp("guarded"))
                        && sizeof(guards) >= 4 )
                        return notify_fail("�Ѿ��кܶ����ڱ���"+ob->name()+"�ˡ�\n");
                }
// end.

                me->set_temp("guarding", ob);
        }
        else if( environment(me)->query("exits/" + arg) ) {
                if( environment(me)->query(SAFE_ENV) )
                        return notify_fail("���ﲻ׼ս������Ҳ��׼��ס����ȥ·��\n");
		/* ���ʵ��û��Ҫ��ʹ��Ϸ����ЩȤζ����ȥ����added & removed by Find.*/
		//if( environment(me)->query("outdoors") && userp(me) )
		//	return notify_fail("�㷢��һ���˺�����ס�������\n");
                me->set_temp("guarding", arg);
        }
        else if( arg!= "cancel" )
                return notify_fail("��Ҫ����˭��ʲô�������ĸ�����\n");

        if( objectp(old_target) ) {
                guards = old_target->query_temp("guarded");
                // added by Find.
                if(arrayp(guards))
                // end.
                guards -= ({ me });
                old_target->set_temp("guarded", guards);
                if( living(old_target) )
                        tell_object( old_target, me->name() + "���ٱ������ˡ�\n");
        } else if( stringp(dir = me->query_temp("pending/guarding")) ) {
                guards = environment(me)->query("guarded/" + dir);
                if( arrayp(guards) ) {
                        guards -= ({ me });
                        environment(me)->set("guarded/" + dir, guards);
                }
                me->delete_temp("pending/guarding");
        }

        if( arg=="cancel" ) {
                write("Ok.\n");
                return 1;
        }

        if( objectp(ob) ) {
                ob->add_temp("guarded", ({ me }) );
                if( living(ob) )
                        message_vision("$N��ʼ����$n��\n", me, ob);
                else
                        message_vision("$Nվ�����ϵ�$nһ���������������ȡ�ߡ�\n", me, ob);
        } else {
                me->set_temp("pending/guarding", arg);
                environment(me)->add("guarded/" + arg, ({ me }));
                message_vision("$N��ʼ��ס�� " + arg + " �ķ������κ���ͨ�С�\n", me);
        }

	if(me->is_fighting())
		me->start_busy(1);
        return 1;
}

int help(object me)
{
        write(@TEXT
ָ���ʽ��guard [<ĳ��>|<����ĳ��>|<ĳ������>|cancel]

���ָ�����������÷�ʽ���ֱ����᣺

guard <ĳ��>      ����<ĳ��>�����������ܵ�����ʱ�������߻��Զ�����ս��������
                  �ܹ�����˳λ�����ڱ�������ǰ�棬���ֻ�й���˳λǰ�ĸ�Ŀ��
                  �Ż��ܵ����������������������ĸ���  guard �㣬��Ͳ�����
                  ���κι�����

guard <����ĳ��>  ��ס���ڵ��ϵ�ĳ����������ֹ�������ã�ֻҪ�㻹��������䣬
                  ����û��æ�������£����˾��޷����������������Ȼ�������
                  �˱��±����Ҳû�취��

guard <ĳ������>  ��סĳ�����ڷ�ֹ�����˴���������뿪���������������������
                  �ĵ��˻���·��������¡���ÿ�γɹ��ĵ�ס���˵�ȥ·��Ҫ�ķ�
		  һ���������������һ�������Ĵ�·����������Ҫͨ������ס����
		  ��·��Ҳ����һ�����յġ�

guard cancel      ȡ����ǰ�� guard ����
guard             �����κβ�������ʾ��Ŀǰ guard �Ķ���

ע�⣬ͨ������ guard <ĳ��> ���������⣬ֻҪ��һ�ƶ���guard ��״̬�ͻ�����
TEXT
        );
        return 1;
}