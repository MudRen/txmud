/******************************************
 * criminal_record.c
 *
 * ��������ڹ���������ʽ�ķ�����б��ﷸͨ����
 * ���桢������Ϊ������Ľ�����һ���뷸���йص�
 * ���ˡ�
 *
 *
 * Ŀǰ���������У�
 * 1. ����ɱ�˷���
 * 2. ���Է���
 *
 *		By Find.
 ******************************************/

inherit F_NATURE;
inherit F_SAVE;
inherit F_DBASE;

class family
{
	string k_name;
	string k_id;
	string name;
	string id;
	int master;
	string date;
}

mapping family_crime = ([]);

mapping criminals = ([]);

/*
��ȡ��¼��ʽ��
"find" : ([
	"crime"  : "killer", // ���ɡ�
	"name"   : "���ֺ�", // chinese name.
	"family" : "����ׯ", // family.
])
*/

void create()
{
	seteuid(getuid());
	set("channel_id", "�ﰸ����");
	restore();
}

string query_save_file() { return DATA_DIR+"crimed";}

string query_placard() /* �˺�����������ŵĲ�������, �������� is an example. */
{
	string head,end,*cris,content;
	int year,month;

	month = query_month();
	year = query_year();

	head ="
	 ���ٸ�ͨ�桷
---------------------------------\n";

	end ="---------------------------------\n\t"
		+MUD_NAME+((year == 0)? "Ԫ":chinese_number(year))+
		"��"+chinese_number(month)+"��\n";

/*********************************
�������������£�

�� ���ɱ�˷� Find������Σ�ա�
   �����������ֺš�
   ��  ����(����)��
   ��  ��������ԭΪ����ׯ���ӡ�
**********************************/

	if(criminals == ([]) || !sizeof(cris = keys(criminals)))
	{
		content = "  ���ڹٸ��������������һƬ��ͣ�
���������೯͢��������˰����
͢�������ۡ�\n";
		return head + content + end;
	}
}

string query_family_placard(string cls)
{


}

// ���ɳ�ɱ��
// ͬ�Ż�ɱ ����
void pass_family_crime(object killer,object victim)
{
	string v_class,k_class;
	class family ff;
	int year,month,day;

	if( !killer
	|| !victim
	|| !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID))
		return;

	if(!userp(killer) )
		return;

	if(!userp(victim) && !victim->is_master())
		return;

	k_class = killer->query("class");
	v_class = victim->query("class");

	// ͬ�Ŷ�ɱ���⴦��
	if( !v_class || k_class == v_class )
		return;

	// �ȼ���ǲ��Ǳ���
	if( stringp(k_class) && userp(victim) && !undefinedp(family_crime[k_class]) )
	{
		class family *crimes;
		int n;
		int flag;
		string id = victim->query("id");

		crimes = family_crime[k_class];
		if( crimes && (n = sizeof(crimes)) )
		{
			for(int i=0;i<n;i++)
			{
				// ��ɱһ�ξ�һ�ʹ�����
				if(crimes[n]->k_id == id)
				{
					crimes[n] = 0;
					flag++;
				}
			}

			if(flag) // ����
			{
				crimes -= ({0});
				family_crime[k_class] = crimes;
				save();
				return;
			}
		}
	}

	ff = new(class family);
	ff->k_name = killer->query("name");
	ff->k_id = killer->query("id");
	ff->name = victim->query("name");
	ff->id = victim->query("id");
	ff->master = userp(victim)?0:1;

	year = query_year();
	month = query_month();
	day = query_day_in_month();

	ff->date = sprintf("%s����%s��%s��%s��",MUD_NAME,
		!year?"Ԫ":chinese_number(year),
		chinese_number(month),
		chinese_number(day) );

	if(undefinedp(family_crime[v_class]))
		family_crime[v_class] = ({ ff });
	else
		family_crime[v_class] += ({ ff });
	save();
}
