// user.c
// by Find.

// �������ܷ�ʹ��
int permit_add_cname(string name)
{
	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID) )
		return 0;

	if(!stringp(name) || (name == ""))
		return 0;

	return DATABASE_D->db_permit_add_cname(name);
}

// �����ʼ��ܷ�ע��
int permit_reg_email(string email)
{
	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID) )
		return 0;

	if( !stringp(email) || (email == "") )
		return 0;

	return DATABASE_D->db_permit_reg_email(email);
}

// ��ʱδ��ע�����δ������ȷ�ϵ����
string *query_exceed_reg_time()
{
	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID) )
		return 0;

	return DATABASE_D->db_query_exceed_reg_time();
}

/**********************
 * flag 0 δ֪״̬    *
 * flag 1 ��ע�����  *
 * flag 2 δע�����  *
 **********************/
varargs void del_user_data(string id,int flag)
{
	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID) )
		return;

	if(!stringp(id) || (id == ""))
		return;

	switch (flag)
	{
		case 1:
			DATABASE_D->db_del_reg_user(id);
			DATABASE_D->del_user_all_pob(id);
			return;
		case 2:
			DATABASE_D->db_del_temp_user(id);
			return;
		default:
			DATABASE_D->db_del_unknow_user(id);
			DATABASE_D->del_user_all_pob(id);
	}
}

int change_cname(string id,string name)
{
	if( !previous_object()
	|| (geteuid(previous_object()) != "Object") )
		return 0;

	if( !stringp(id) || (id == "")
	|| !stringp(name) || (name == "") )
		return 0;

	return DATABASE_D->db_change_chinese_name(id,name);
}

// �������е���ʽע���������
int count_reg_user()
{
	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID) )
		return 0;

	return DATABASE_D->db_count_reg_user();
}

// ����ҵ���������
void newbie_buildup(string id, string name)
{
	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID) )
		return;

	if(!stringp(id) || (id == "")
	|| !stringp(name) || (name == ""))
		return;

	DATABASE_D->db_newbie_buildup(id,name);
}

void newbie_reg(string id, string email)
{
	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID) )
		return;

	if(!stringp(id) || (id == "")
	|| !stringp(email) || (email == ""))
		return;

	DATABASE_D->db_newbie_reg(id,email);
}

void newbie_success_reg(string id)
{
	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID) )
		return;

	if(!stringp(id) || (id == ""))
		return;

	DATABASE_D->db_newbie_success_reg(id);
}

string query_register_station(string id)
{
	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID) )
		return 0;

	if( !stringp(id) || (id == ""))
		return 0;

	return DATABASE_D->db_query_register_station(id);
}
