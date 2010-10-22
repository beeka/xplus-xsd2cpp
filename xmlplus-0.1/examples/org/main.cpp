
#include <iostream>
#include <string>

#include "XSD/UserOps.h"
#include "org/all-include.h"

  
int main (int argc, char**argv)
{
  XSD_USER_OPS::xsd_main(argc, argv);
}

DOM::Document* createXsdDocument(bool buildTree)
{
  org::Document* xsdDoc = new org::Document(buildTree);
  
  return xsdDoc;
}

DOM::Document* createXsdDocument(string inFilePath)
{
  XPlusFileInputStream is;
  is.open(inFilePath.c_str(), ios::binary);

  org::Document* xsdDoc = new org::Document(false);

  is >> *xsdDoc; 
  return xsdDoc;
}

//
// Following functions are templates.
// You need to put code in the context
//

  
// template function to populate the Tree with values
void populateDocument(DOM::Document* pDoc)
{
  /*
   Jim Barnette    : org head

   Paul V. Biron : engg head
   
   Allen Brown : proj1 head
   Charles E. Campbell
   Wayne Carr

   Lee Buck : proj2 head
   Peter Chen
   David Cleary

   Legal:
   Don Box :legal head
   Dan Connolly
   Ugo Corda
  */

  org::Document* xsdDoc = dynamic_cast<org::Document *>(pDoc);
  // write code to populate the Document here
  org::organization* pOrgn = xsdDoc->element_organization();
  pOrgn->set_leaderId("jimb");
  pOrgn->set_attr_id("nasa");
  pOrgn->set_name("NASA");

  // all employees
  pOrgn->element_allEmployees()->set_count_employee(11);
  org::hr::Types::Employee* pEmpl = NULL;
  
  pEmpl = pOrgn->element_allEmployees()->element_employee_at(0);
  pEmpl->set_name("Jim Barnette");
  pEmpl->set_userId("jimb");
  pEmpl->set_title("org head");
  pEmpl->element_reportees()->add_userId_string("paulb");
  pEmpl->element_reportees()->add_userId_string("donb");
  
  pEmpl = pOrgn->element_allEmployees()->element_employee_at(1);
  pEmpl->set_name("Paul V. Biron");
  pEmpl->set_userId("paulb");
  pEmpl->set_title("Engg head");
  pEmpl->element_reportees()->add_userId_string("allenb");
  pEmpl->element_reportees()->add_userId_string("leeb");
  pEmpl->set_reportsTo("jimb");
  
  pEmpl = pOrgn->element_allEmployees()->element_employee_at(2);
  pEmpl->set_name("Don Box");
  pEmpl->set_userId("donb");
  pEmpl->set_title("Legal head");
  pEmpl->element_reportees()->add_userId_string("danc");
  pEmpl->element_reportees()->add_userId_string("ugoc");
  pEmpl->set_reportsTo("jimb");
  
  pEmpl = pOrgn->element_allEmployees()->element_employee_at(3);
  pEmpl->set_name("Allen Brown");
  pEmpl->set_userId("allenb");
  pEmpl->set_title("Proj1 head");
  pEmpl->element_reportees()->add_userId_string("charlese");
  pEmpl->element_reportees()->add_userId_string("waynec");
  pEmpl->set_reportsTo("paulb");
  
  pEmpl = pOrgn->element_allEmployees()->element_employee_at(4);
  pEmpl->set_name("Lee Buck");
  pEmpl->set_userId("leeb");
  pEmpl->set_title("Proj2 head");
  pEmpl->element_reportees()->add_userId_string("peterc");
  pEmpl->element_reportees()->add_userId_string("davidc");
  pEmpl->set_reportsTo("paulb");
  
  pEmpl = pOrgn->element_allEmployees()->element_employee_at(5);
  pEmpl->set_name("Charles E Campbell");
  pEmpl->set_userId("charlese");
  pEmpl->set_title("SMTS");
  pEmpl->set_reportsTo("allenb");

  pEmpl = pOrgn->element_allEmployees()->element_employee_at(6);
  pEmpl->set_name("Wayne Carr");
  pEmpl->set_userId("waynec");
  pEmpl->set_title("SMTS");
  pEmpl->set_reportsTo("allenb");
  
  pEmpl = pOrgn->element_allEmployees()->element_employee_at(7);
  pEmpl->set_name("Peter Chen");
  pEmpl->set_userId("peterc");
  pEmpl->set_title("SMTS");
  pEmpl->set_reportsTo("leeb");
  
  pEmpl = pOrgn->element_allEmployees()->element_employee_at(8);
  pEmpl->set_name("David Cleary");
  pEmpl->set_userId("davidc");
  pEmpl->set_title("SMTS");
  pEmpl->set_reportsTo("leeb");

  pEmpl = pOrgn->element_allEmployees()->element_employee_at(9);
  pEmpl->set_name("Dan Connolly");
  pEmpl->set_userId("danc");
  pEmpl->set_title("Legal Advisor");
  pEmpl->set_reportsTo("donb");
  
  pEmpl = pOrgn->element_allEmployees()->element_employee_at(10);
  pEmpl->set_name("Ugo Corda");
  pEmpl->set_userId("ugoc");
  pEmpl->set_title("Legal Advisor");
  pEmpl->set_reportsTo("donb");
  

  org::Types::Departments::engineering* pEnggDept = pOrgn->element_departments()->element_engineering();
  pEnggDept->set_attr_id("nasa.deperatments.engineering");
  pEnggDept->set_leaderId("paulb");
  pEnggDept->set_count_project(2);

  org::engg::Types::EnggDept::project* pProj = NULL;
  
  pProj = pEnggDept->element_project_at(0);
  pProj->set_leaderId("allenb");
  pProj->element_engineers()->add_userId_string("charlese");
  pProj->element_engineers()->add_userId_string("waynec");
  pProj->set_projectName("The unmanned moon mission 2015");

  pProj = pEnggDept->element_project_at(1);
  pProj->set_leaderId("leeb");
  pProj->element_engineers()->add_userId_string("peterc");
  pProj->element_engineers()->add_userId_string("davidc");
  pProj->set_projectName("The manned moon mission 2020");

  org::Types::Departments::legal* pLegalDept = pOrgn->element_departments()->element_legal();
  pLegalDept->set_attr_id("nasa.deperatments.legal");
  pLegalDept->set_leaderId("donb");
  pLegalDept->element_legalAdvisors()->add_userId_string("danc");
  pLegalDept->element_legalAdvisors()->add_userId_string("ugoc");
  
}

void updateOrConsumeDocument(DOM::Document* pDoc)
{
  org::Document* xsdDoc = dynamic_cast<org::Document *>(pDoc);
  // write code to operate on the populated-Document here

}

  
